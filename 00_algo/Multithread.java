import java.util.*;

public class Multithread{
    public static void main(String args[]){
        System.out.println("60004220217");
        Tickets t = new Tickets(5);
        Booking b1 = new Booking(t);
        Booking b2 = new Booking(t);
        b1.start();
        b2.start();
    }
}

class Tickets{
    int n = 10;
    Tickets(int n){
        this.n=n;
    }
    boolean buyTickets(int n){
        if(n<=this.n){
            this.n=this.n-n;
            return true;
        }else{
            return false;
        }
    }
    void bookTickets(){
        System.out.println("Welcome to the system!");
        System.out.println("Tickets available: "+n);
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter amount of tickets you need to buy: ");
        int num = sc.nextInt();
        boolean booked = buyTickets(num);
        System.out.println(booked?"Successfully booked":"Booking failed");
    }
}

class Booking extends Thread{
    Tickets t;
    Booking(Tickets t){
        this.t=t;
    }
    
    public void run(){
        t.bookTickets();
        try{
            Thread.sleep(2000);
        }catch(InterruptedException e){}
    }
}
