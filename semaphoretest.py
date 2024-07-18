import threading
import time
import random

# 최대 동시 다운로드 수
MAX_DOWNLOADS = 4

# 세마포 설정
download_slots = threading.Semaphore(MAX_DOWNLOADS)
mutex = threading.Semaphore(1)

def download_file(file_id):
    global download_slots
    while True:
        print(f"File {file_id} waiting to download")
        download_slots.acquire()  # 빈 다운로드 슬롯이 생길 때까지 대기
        mutex.acquire()
        print(f"File {file_id} is downloading")
        mutex.release()
        time.sleep(random.uniform(2, 5))  # 다운로드 시간

        print(f"File {file_id} finished downloading")
        mutex.acquire()
        print(f"File {file_id} download completed")
        mutex.release()
        download_slots.release()  # 빈 다운로드 슬롯이 생겼음을 알림
        time.sleep(random.uniform(3, 6))  # 다음 파일 다운로드 전 대기

# 스레드 생성
files = [threading.Thread(target=download_file, args=(i,)) for i in range(8)]

# 스레드 시작
for file in files:
    file.start()

# 메인 스레드가 종료되지 않도록 대기
for file in files:
    file.join()