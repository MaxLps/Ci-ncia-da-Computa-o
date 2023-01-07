
public class Mago extends Personagem{
	private int mana;
	
	public int getMana() {
		return mana;
	}
	public void setMana(int mana) {
		this.mana = mana;
	}
	public int lancarMagia() {
		if(mana>0) {
			return (int) (mana * getForca());
		}
		return 0;
	}
	public Mago(String nome, double pontuacao, double vida,
			Personagem.Sexo sexo, Item[] item) {
		super(nome, pontuacao, vida, sexo, item);
	}
}
