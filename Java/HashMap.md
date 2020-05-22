## HashMap
- 해싱으로 기본으로 해서 최선 O(1), 최악 log n/m
  * threshold가 넘어가면 Red black tree
- Collection Framework들은 기본적으로 shallow copy를 지원하기에 deep copy는 직접 복사하는 로직을 짜야 한다.
- putAll, clone 등등 모두 shallow copy

### HashMap 기본 사용법
```java

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class helloworld {

    public static void main(String[] arg) {
        HashMap<Integer, Integer> h = new HashMap<>();

        h.put(1,1);
        h.put(2,1);
        h.put(3,1);
        h.put(4,1);
        h.put(5,1);
        h.put(6,1);


        if(h.containsKey(1)){ // key 확인
            System.out.println("1 있다");
            h.remove(1); // 제거
        }

        if(!h.containsKey(1)){
            System.out.println("1 없다");
        }

        //map 순회
        Iterator<Map.Entry<Integer, Integer>> iterator = h.entrySet().iterator();

        while(iterator.hasNext()){
            Map.Entry<Integer, Integer> lm = iterator.next();
            System.out.println(lm.getKey() + "/" + lm.getValue());
        }
    }
    //출처: https://vaert.tistory.com/107
}

```

### HashMap shallow copy

```java
public class ExampleClass {
    public String data;

    public ExampleClass(String data){
        this.data = data;
    }
}
```

```java
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class helloworld {

    public static void main(String[] arg) {
        HashMap<Integer, ExampleClass> h = new HashMap<>();

        h.put(1,new ExampleClass("Korea"));
        h.put(2,new ExampleClass("Korea"));
        h.put(3,new ExampleClass("Korea"));

        HashMap<Integer, ExampleClass> copyHashMap = h; //Shallow Copy

        Iterator<Map.Entry<Integer, ExampleClass>> iterator = h.entrySet().iterator();

        while(iterator.hasNext()){
            Map.Entry<Integer, ExampleClass> cur =  iterator.next();
            System.out.print(cur.getKey() + "/" + cur.getValue().data + " ");
        }

        System.out.println("");

        /* h를 바꾸면 copyHashMap도 바뀐다. 주소값을 가져간 것이기에...  */
        h.get(1).data = "US";
        h.get(2).data = "US";
        h.get(3).data = "US";

        Iterator<Map.Entry<Integer, ExampleClass>> iterator1 = copyHashMap.entrySet().iterator();

        while(iterator1.hasNext()){
            Map.Entry<Integer, ExampleClass> cur =  iterator1.next();
            System.out.print(cur.getKey() + "/" + cur.getValue().data + " ");
        }
    }

}

```

### HashMap Deep Copy

```java
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class helloworld {
    /*Shallow Copy*/
//    public static HashMap<Integer,ExampleClass> copyHM(HashMap<Integer,ExampleClass> origin){
//        HashMap<Integer, ExampleClass> hashMap = new HashMap<>();
//        hashMap.putAll(origin);
//        return hashMap;
//    }

    public static void main(String[] arg) {
        HashMap<Integer, ExampleClass> h = new HashMap<>();

        h.put(1,new ExampleClass("Korea"));
        h.put(2,new ExampleClass("Korea"));
        h.put(3,new ExampleClass("Korea"));

        HashMap<Integer, ExampleClass> copyHashMap = new HashMap<>();


        //Deep Copy: 직접 다 복사
        for(Map.Entry<Integer,ExampleClass> entry: h.entrySet()) {
            copyHashMap.put(entry.getKey(), new ExampleClass(entry.getValue().data));
        }


        Iterator<Map.Entry<Integer, ExampleClass>> iterator = h.entrySet().iterator();

        while(iterator.hasNext()){
            Map.Entry<Integer, ExampleClass> cur =  iterator.next();
            System.out.print(cur.getKey() + "/" + cur.getValue().data + " ");
        }

        System.out.println("");

        h.get(1).data = "US";
        h.get(2).data = "US";
        h.get(3).data = "US";

        Iterator<Map.Entry<Integer, ExampleClass>> iterator1 = copyHashMap.entrySet().iterator();

        while(iterator1.hasNext()){
            Map.Entry<Integer, ExampleClass> cur =  iterator1.next();
            System.out.print(cur.getKey() + "/" + cur.getValue().data + " ");
        }
    }

}
```

