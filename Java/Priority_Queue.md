```java
public class ExampleClass implements Comparable<ExampleClass> {
    public String data;
    public Integer data2;

    public ExampleClass(String data, Integer data2){
        this.data = data;
        this.data2 = data2;
    }

    @Override
    public int compareTo(ExampleClass o) {
        //오름차순
        if(this.data.compareTo(o.data) > 0){ //앞인 this가 o.data보다 큰데, return 1을 하기에 바꾼다.
            return 1;//1이면 자리 바꾼다.
        }
        else if(this.data.compareTo(o.data) == 0){
            if(this.data2 > o.data2){
                return 1;
            }
        }

        return -1;
    }
}


import java.util.*;

public class helloworld {

    public static void main(String[] arg) {
        PriorityQueue<ExampleClass> p = new PriorityQueue<>();

        p.add(new ExampleClass("가",2));
        p.add(new ExampleClass("가",1));
        p.add(new ExampleClass("가",3));
        p.add(new ExampleClass("가",6));
        p.add(new ExampleClass("가",0));
        p.add(new ExampleClass("다",1));
        p.add(new ExampleClass("나",1));
        p.add(new ExampleClass("가",7));


        while(!p.isEmpty()){
            ExampleClass cur = p.peek();
            p.poll();

            System.out.println(cur.data + "/" + cur.data2);
        }
    }
}

```

### 참고자료
- [우선순위 큐(Priority Queue)](https://cjh5414.github.io/priorityqueue/)
- [Java Queue, Priority Queue 예제](https://gamjatwigim.tistory.com/72)

