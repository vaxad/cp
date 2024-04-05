import java.util.Scanner;

class MySemaphore{
	int permission;
	MySemaphore(int permission){
		this.permission = permission;
	}
	synchronized void acquire() throws InterruptedException{
		while(permission == 0){
			wait();
		}
		permission--;
	}
	synchronized void release() {
		permission++;
		notify();
	}
	
}

class BufferStateCriticalSection{
	int bufferArray[];
	int size,item;
	int producerPointer,consumerPointer;
	MySemaphore semProd,semCons,empty,full;
	BufferStateCriticalSection(int size){
		this.size = size;
		bufferArray = new int[size];
		producerPointer = 0;
		consumerPointer = 0;
		semProd = new MySemaphore(1);
		semCons = new MySemaphore(0);
		empty = new MySemaphore(size);
		full = new MySemaphore(0);
	}
	void put(int item){
		try{
		semProd.acquire();
		empty.acquire();
		}
		catch(Exception e){
			System.out.println("");
		}
		this.item = item;
		bufferArray[producerPointer] = this.item;
		full.release();
		producerPointer++;
		System.out.println("Produced item: "+this.item+"\nNo of items present: "+full.permission+"\nEmpty Spaces: "+empty.permission+"\nProducer Pointer position: "+producerPointer+"\nProducer Pointer position: "+consumerPointer);
		System.out.println("");
		semCons.release();
	}
	void get(){
		try{
		semCons.acquire();
		full.acquire();
		}
		catch(Exception e){
			System.out.println("");
		}
		this.item = bufferArray[consumerPointer];
		consumerPointer++;
		empty.release();
		System.out.println("Consumed item: "+this.item+"\nNo of items present: "+full.permission+"\nEmpty Spaces: "+empty.permission+"\nProducer Pointer position: "+producerPointer+"\nConsumer Pointer position: "+consumerPointer);
		System.out.println("");
		semProd.release();
	}
}

class Producer extends Thread{
	BufferStateCriticalSection bffcs;
	Producer(BufferStateCriticalSection bffcs){
		this.bffcs = bffcs;
	}
	public void run(){
		for(int i=0;i<bffcs.size;i++){
			bffcs.put(i);
		}
	}
}

class Consumer extends Thread{
	BufferStateCriticalSection bffcs;
	Consumer(BufferStateCriticalSection bffcs){
		this.bffcs = bffcs;
	}
	public void run(){
		for(int i=0;i<bffcs.size;i++){
			bffcs.get();
		}
	}
}

class SolutionUsingSemaphores{
	public static void main(String args[]){
		int size;
		Producer p;
		Consumer c;
		BufferStateCriticalSection bffcs;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the Size of the BufferArray: ");
		size = sc.nextInt();
		bffcs = new BufferStateCriticalSection(size);
		p = new Producer(bffcs);
		c = new Consumer(bffcs);
		p.start();
		c.start();
		sc.close();
	}
}