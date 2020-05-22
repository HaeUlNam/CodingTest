### StringTokenizer

```java
import java.util.StringTokenizer;

public class helloworld {

    public static void main(String[] arg) {
        String sss = "대한민국/미국,일본,중국/러시아";
        //delimiter를 여러 개 지정해두면 이를 기준으로 tokenizer 작동
        //마지막 paramter는 지정안하면 false인데, false일 경우는 delimiter 출력 x, true는 출력 o
        StringTokenizer tokenizer = new StringTokenizer(sss,"/,", true);

        while(tokenizer.hasMoreElements()){
            String cur = tokenizer.nextToken();
            System.out.println(cur);
        }

    }

}

```

### StringBuilder

```java
public class helloworld {

    public static void main(String[] arg) {
        String sss = "cake";

        StringBuilder stringBuilder = new StringBuilder(sss);

        stringBuilder.append(" acaa ");
        stringBuilder.append(" bbcb ");

        System.out.println(stringBuilder);
        System.out.println(stringBuilder.reverse()); //역순
        System.out.println(stringBuilder.capacity()); //할당된 메모리 크기
        System.out.println(stringBuilder.length()); //실제 길이


        sss = stringBuilder.toString(); //StringBuilder to String
    }

}
```


### 참고자료
- [Java StringTokenizer 알아보기](https://dlfma1985.tistory.com/52)
