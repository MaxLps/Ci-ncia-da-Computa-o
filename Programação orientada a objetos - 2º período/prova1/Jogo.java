
public class Jogo {
	enum Estado {ATIVO, PAUSADO, GAMEOVER};
	private Fase[] fases = new Fase[100];
	private Personagem[] personagens = new Personagem[4];
	private static int numeroDePersonagens;
	private Estado estado;
	public Fase[] getFases() {
		return fases;
	}
	public void setFases(Fase[] fases) {
		this.fases = fases;
	}
	public Personagem[] getPersonagens() {
		return personagens;
	}
	public void setPersonagens(Personagem[] personagens) {
		this.personagens = personagens;
	}
	public static int getNumeroDePersonagens() {
		return numeroDePersonagens;
	}
	public static void setNumeroDePersonagens(int numeroDePersonagens) {
		Jogo.numeroDePersonagens = numeroDePersonagens;
	}
	public Estado getEstado() {
		return estado;
	}
	public void setEstado(Estado estado) {
		this.estado = estado;
	}
	public Jogo(Fase[] fases, Personagem[] personagens, Jogo.Estado estado) {
		this.fases = fases;
		this.personagens = personagens;
		this.estado = estado;
	}
}
