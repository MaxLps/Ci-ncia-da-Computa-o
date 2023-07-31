
public class Fase {
	private final String nome;
	private int dificuldade;
	private static int numeroDePersonagens = 6;
	public int getDificuldade() {
		return dificuldade;
	}
	public void setDificuldade() { //qPersonagens é passado na main de acordo com o tamanho do vetor personagem
		dificuldade = numeroDePersonagens + 1;
		if(dificuldade > 5) {
			dificuldade = 5;
		}
	}
	public String getNome() {
		return nome;
	}
	public Fase(String nome, int dificuldade) {
		this.nome = nome;
		this.dificuldade = dificuldade;
	}
	
	
}
