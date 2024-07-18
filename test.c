#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>

char send_ch[10], receive_ch[10];

void* send_routine(void* param){ // 발신 스레드
        struct mq_attr pr_attr;
        pr_attr.mq_maxmsg = 20;
        pr_attr.mq_msgsize = 128;
        mqd_t pr_mq;
        char pr_buf[128] = {0,};

        pr_mq = mq_open(send_ch, O_WRONLY, 0666, &pr_attr);
        if (pr_mq == -1) {
                perror("send routine open error\n");
                exit(0);
        }

        while (strcmp(pr_buf, "exit\0") != 0) {
                printf("send message: ");
                gets(pr_buf);
                if ((mq_send(pr_mq, pr_buf, strlen(pr_buf), 1))==-1){
                        perror("send mq_send error\n");
                }
        }

        mq_close(pr_mq);
}

void* receive_routine(void* param){ // 수신 스레드
        struct mq_attr co_attr;
        co_attr.mq_maxmsg = 20;
        co_attr.mq_msgsize = 128;
        mqd_t co_mq;
        char co_buf[128] = {0,};

        co_mq = mq_open(receive_ch, O_RDWR | O_CREAT, 0666, &co_attr);
        if (co_mq == -1){
                perror("receive routine open error\n");
                exit(1);
        }

        while (strstr(co_buf, "exit") == NULL){
                for (int i=0; i<128; i++) co_buf[i] = '\0';
                if ((mq_receive(co_mq, co_buf, co_attr.mq_msgsize, NULL))==-1){
                        perror("receive mq_receive error\n");
                }
                else {
                printf("[Frome prod]: %s\n", co_buf);
                }
        }

        mq_close(co_mq);
        mq_unlink(receive_ch);
}

int main(void){
        printf("send_ch:\n");
        gets(send_ch);
        printf("receive_ch:\n");
        gets(receive_ch);

        pthread_t tid[2]; // 0: 수신 스레드 / 1: 발신 스레드
        pthread_attr_t p_attr;
        pthread_attr_init(&p_attr);

        // 수신 스레드
        pthread_create(&tid[0], &p_attr, receive_routine, NULL);

        getchar();

        // 발신 스레드
        pthread_create(&tid[1], &p_attr, send_routine, NULL);

        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);

        return 0;
}
