
abstract class Item {
	private final String nome;
	private final double forca;
	private final double inteligencia;
	private final double vida;
	
	public String getNome() {
		return nome;
	}

	public double getForca() {
		return forca;
	}
	public double getInteligencia() {
		return inteligencia;
	}
	public double getVida() {
		return vida;
	}
	public Item(String nome, double forca, double inteligencia, double vida) {
		this.nome = nome;
		this.forca = forca;
		this.inteligencia = inteligencia;
		this.vida = vida;
	}
	
}
