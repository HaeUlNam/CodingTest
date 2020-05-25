### C++ stringstream

- sstream 헤더에 들어있는 stringstream을 사용하면 단 하나의 문자만 기준으로 split할 수 있다. 따라서 아래와 같은 방법으로 하면 여러 개의 문자를 기준으로 split
이 가능하다.

### C++ strtok 사용

- string을 통째로 넘기는 건 안되지만 아래와 같이 0번째의 주소를 넘기는 것은 가능하다.
- 따라서 아래와 같이 주소를 넘기고 진행.
- cstring header에 

```c++
char * tok = strtok(&cur[0],"],");
while(tok != NULL){
  tokList.push_back(tok);
  tok = strtok(NULL, "],");
  //여기에 tok을 출력하게 되면 세그먼트 폴트가 뜨게 된다...ㅠㅠ
}
```

### strtok의 원리
- 링크 참조
- https://dojang.io/mod/page/view.php?id=376
