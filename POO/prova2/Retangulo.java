package p2;

public class Retangulo extends Forma {
	private float largura;
	private float comprimento;
	
	public float getLargura() {
		return largura;
	}

	public void setLargura(float largura) {
		this.largura = largura;
	}

	public float getComprimento() {
		return comprimento;
	}

	public void setComprimento(float comprimento) {
		this.comprimento = comprimento;
	}
	
	@Override
	public void calcArea() {
		setArea(largura * comprimento); 
	}
	
	@Override
	public void calcPerimetro() {
		setPerimetro(2*largura + 2*comprimento);
	}
	
	@Override
	public void imprimir() {
		System.out.println("Area Retangulo = "+getArea()+ " Perimetro Retangulo = "+ getPerimetro());
	}
	
	public Retangulo(float l, float c) {
		this.largura = l;
		this.comprimento = c;
	}

}
