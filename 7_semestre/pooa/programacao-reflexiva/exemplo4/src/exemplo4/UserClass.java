package exemplo4;

public class UserClass extends BaseFrameworkClass {

    @TrackExecution
    public void methodOne() {
        System.out.println("Executing methodOne.");
    }

    @TrackExecution
    public void methodTwo() {
        System.out.println("Executing methodTwo.");
    }

    public void methodThree() {
        System.out.println("Executing methodThree.");
    }
}

