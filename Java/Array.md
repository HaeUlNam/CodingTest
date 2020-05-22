```java
import java.util.*;

public class helloworld {

    public static void main(String[] arg) {
        Integer arr[] = new Integer[]{7,6,5,4,3,2,1};

        //Arrays.sort(arr);//오름차순
        Arrays.sort(arr,Collections.reverseOrder()); //내림차순(primitive type은 사용불가)

        for(int i = 0; i < arr.length; ++i){
            System.out.println(arr[i]);
        }
    }
}
```

### 참고자료

- [Java 정렬 오름차순 vs 내림차순](https://jamesdreaming.tistory.com/162)
