import sys

siteNum, searchNum = map(int, input().split())
site_N_pw = {}

for i in range(siteNum):
    siteName, sitePw = input().split() # 사이트 이름과 사이트 비밀번호 입력
    site_N_pw[siteName] = sitePw

for i in range(searchNum):
    print(site_N_pw[input()])  # 입력받은 사이트 주소를 키로하여 해당 사이트의 비밀번호 출력
