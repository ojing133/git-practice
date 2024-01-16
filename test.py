import json
import requests

from urllib import request

token = 'ZQAAAUNOgxnBwRiYhWuaMYKmWgvhxxMC88ZNfM2ppy5HTlIG1zqzp11GHZY9B4dkpGhbGR6FCMs7wbG3x3lHhmApJb88crXLhUfT7yPi1TgU1yQW'

def get_bands():
    url = 'https://openapi.band.us/v2.1/bands?access_token={}'.format(token)
    req = request.Request(url)
    res = request.urlopen(req)
    decoded = res.read().decode("utf8")
    json_dict = json.loads(decoded)
    return json_dict


def create_post(band_key, content, do_push=True):
    url = 'https://openapi.band.us/v2.2/band/post/create'
    data = {'access_token': token, 'band_key': band_key, 'content': content, 'do_push': do_push}
    with requests.post(url, data) as resp:
        json_dict = json.loads(resp.text)
        return json_dict


for i in range(len(get_bands()['result_data']['bands'])):
    if get_bands()['result_data']['bands'][i]['name'] == '23 프기 파이썬 테스트':
        print(create_post(get_bands()['result_data']['bands'][i]['band_key'], 'test'))
