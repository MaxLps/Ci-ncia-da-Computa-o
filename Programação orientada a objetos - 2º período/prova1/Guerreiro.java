
public class Guerreiro extends Personagem {
	private int estamina=0;
	
	public int getEstamina() {
		return estamina;
	}
	public void setEstamina(int estamina) {
		this.estamina = estamina;
	}
	public int ataquePoderoso() {
		if(estamina>0) {
			return (int) (estamina * getForca());
		}
		return 0;
	}
	public Guerreiro(String nome, double pontuacao, double vida,
			Personagem.Sexo sexo, Item[] item) {
		super(nome, pontuacao, vida, sexo, item);
	}
}
