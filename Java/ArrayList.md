## ArrayList
- 배열처럼 사용

### 기본 사용법

```java
ArrayList<ExampleClass> arrayList = new ArrayList<>();
arrayList.add(new ExampleClass("가",1));
arrayList.add(new ExampleClass("가",2));
arrayList.add(new ExampleClass("가",3));
arrayList.add(new ExampleClass("가",4));
arrayList.add(new ExampleClass("가",5));
arrayList.add(new ExampleClass("라",2));
arrayList.add(new ExampleClass("나",1));
arrayList.add(new ExampleClass("다",1));


for(int i = 0; i < arrayList.size(); ++i){
  System.out.print(arrayList.get(i).data + "/" + arrayList.get(i).data2 + " ");
}
```

### Comparable

- 음수 또는 0이면 객체의 자리가 그대로 유지되며, 양수인 경우에는 두 객체의 자리가 바뀐다.
- this가 앞에 있고, parameter 객체가 뒤에 있다고 생각하면 된다.

```java
import java.util.Collections;

public class ExampleClass implements Comparable<ExampleClass> {
    public String data;
    public Integer data2;

    public ExampleClass(String data, Integer data2){
        this.data = data;
        this.data2 = data2;
    }

    @Override
    public int compareTo(ExampleClass o) {
        if(this.data.compareTo(o.data) > 0){
            return 1;
        }
        else if(this.data.compareTo(o.data) == 0){
            if(this.data2 > o.data2){
                return 1;
            }
        }

        return -1;
    }
}

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class helloworld {

    public static void main(String[] arg) {
        ArrayList<ExampleClass> arrayList = new ArrayList<>();
        arrayList.add(new ExampleClass("가",5));
        arrayList.add(new ExampleClass("가",4));
        arrayList.add(new ExampleClass("가",3));
        arrayList.add(new ExampleClass("가",2));
        arrayList.add(new ExampleClass("가",1));
        arrayList.add(new ExampleClass("라",2));
        arrayList.add(new ExampleClass("나",1));
        arrayList.add(new ExampleClass("라",1));
        arrayList.add(new ExampleClass("다",1));


        for(int i = 0; i < arrayList.size(); ++i){
            System.out.print(arrayList.get(i).data + "/" + arrayList.get(i).data2 + " ");
        }

        Collections.sort(arrayList);

        System.out.println("");

        for(int i = 0; i < arrayList.size(); ++i){
            System.out.print(arrayList.get(i).data + "/" + arrayList.get(i).data2 + " ");
        }
    }

}
```


### 참고자료
- [[Java] Comparable와 Comparator의 차이와 사용법](https://gmlwjd9405.github.io/2018/09/06/java-comparable-and-comparator.html)
