package composite;

import java.util.ArrayList;


abstract class Element {
    abstract void add();
    abstract void remove();
    abstract int calculatePrice();
    abstract void showContent();
}

class Object extends Element {
    string name;
    int price;

    int calculatePrice() {
        return price;
    }

    void showContent() {
        System.out.println("Element:" + name);
    }
}

class Box extends Element {
    string name;
    int totalPrice;
    List<Element> elements = new ArrayList<Element>();

    int calculatePrice() {
        for (Element element : elements) {
            totalPrice += element.calculatePrice();
        }
    }

    void add(Element element) {
        elements.add(element);
    }

    void remove(Element element) {
        elements.remove(element);
    }

    void showContent() {
        System.out.println("This is the Box:" + name);
        for (Element element : elements) {
            element.showContent();
        }
    }
}

public class main {
    Element box1 = new Box("Box1");
    Element box2 = new Box("Box2");
    Element box3 = new Box("Box3");

    Element object1 = new Object("Object1", 10);
    Element object2 = new Object("Object2", 20);
    Element object3 = new Object("Object3", 30);
    Element object4 = new Object("Object4", 40);
    Element object5 = new Object("Object5", 50);
    Element object6 = new Object("Object6", 60);

    box1.add(object1);
    box1.add(object2);
    box1.add(box2);

    box2.add(object3);
    box2.add(object4);
    box2.add(box3);

    box3.add(object5);
    box3.add(object6);

    box1.showContent();
}