package code;

public class OpenWorld {

	public static void main(String[] args) {
		if(args[0] == "generate") {
			generate();
		} else {
			System.out.println("Command '" + args[0] + "' not found");
		}
	}
	
	static void generate() {
		World world = new World();
		System.out.println(world.name);
	}
	
	void importWorld() {
		
	}
	
	void exportWorld() {
		
	}
}
