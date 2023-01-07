
abstract class Personagem {
	enum Sexo{MASCULINO, FEMENINO};
	private final String nome;
	private double pontuação;
	private double forca;
	private double inteligencia;
	private double vida;
	private Sexo sexo;
	private Item[] item = new Item[2];
	public String getNome() {
		return nome;
	}
	public double getPontuação() {
		return pontuação;
	}
	public void setPontuação(double pontuação) {
		this.pontuação = pontuação;
	}
	public double getForca() {
		return forca;
	}
	public void setForca(int forca) {
		this.forca = forca;
	}
	public double getInteligente() {
		return inteligencia;
	}
	public void setInteligente(double inteligente) {
		this.inteligencia = inteligente;
	}
	public double getVida() {
		return vida;
	}
	public void setVida(double vida) {
		this.vida = vida;
	}
	public Sexo getSexo() {
		return sexo;
	}
	public void setSexo(Sexo sexo) {
		this.sexo = sexo;
	}
	public Item[] getItem() {
		return item;
	}
	public void setItem(Item[] item) {
		this.item = item;
	}
	public Personagem(String nome, double pontuação, double vida,
		Personagem.Sexo sexo, Item[] item) {
		this.nome = nome;
		this.pontuação = pontuação;
		if(sexo == Personagem.Sexo.MASCULINO) {
			this.forca = 10;
			this.inteligencia = 5;
		}
		if(sexo == Personagem.Sexo.FEMENINO) {
			this.forca = 5;
			this.inteligencia = 10;
		}
		this.vida = vida;
		this.sexo = sexo;
		this.item = item;
	}
	
}
