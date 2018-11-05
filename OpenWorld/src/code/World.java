package code;

public class World {

	String name;
	
	public World() {
		name = GenerateRandom.getName("data/random/world_region.txt");
	}
}
