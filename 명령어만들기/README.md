📂 명령어 만들기 과제

50개의 리눅스 명령어를 C언어와 시스템콜로 직접 구현하였습니다.  
명령어 이름은 `sms_` 접두어를 붙여 일관성 있게 작성했습니다.  

📌 명령어 범주

| 범주 | 설명 | 예시 |

| 파일/디렉토리 | 디렉토리 생성, 이동 등 | sms_ls, sms_cd |
| 파일 내용 처리 | 파일 출력, 병합 등 | sms_cat, sms_head |
| 프로세스/시스템 | 프로세스 확인, 종료 등 | sms_ps, sms_kill |
| 사용자/권한 | 사용자 정보, 권한 설정 | sms_chmod, sms_whoami |
| 네트워크/기타 | ping, ip확인 등 | sms_ping, sms_hostname |

- C언어
- 시스템콜: `open()`, `read()`, `write()`, `fork()`, `execve()`, `socket()` 등
- 컴파일 예시: `gcc sms_cat.c -o sms_cat`

📁 구성 방식

- 폴더별로 범주 구분
- 각 명령어별로 `.c` 파일 구현  
  → 나머지 명령어는 동일한 시스템콜 구조로 구현됨
