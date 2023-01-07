package p2;

public class Elipse extends Forma implements Excentricidade  {
	private float a;
	private float b;
	private float e;
	
	public float getE() {
		return e;
	}


	public void setE(float e) {
		this.e = e;
	}


	public float getA() {
		return a;
	}


	public void setA(float a) {
		this.a = a;
	}


	public float getB() {
		return b;
	}


	public void setB(float b) {
		this.b = b;
	}

	@Override
	public void calcPerimetro() {
		if(a == b) {
			setPerimetro((float) (Math.PI * Math.sqrt(2*(a*a + b*b) - (a-b)*(a-b)/2)));
		}
		else {
			setPerimetro((float) (2*Math.PI*a));
		}
	}	
	@Override
	public void calcArea() {
		setArea((float) (Math.PI * a * b));
		
	}
	
	@Override
	public void excentricidade() {
		setE((float) Math.sqrt(1 - (b*b)/(a*a)));
	}
	
	@Override
	public void imprimir() {
		System.out.println("Area Elipse = "+getArea()+ " Perimetro Elipse = "+ getPerimetro()+ " Excentricidade = "+getE());
	}
	
	public Elipse(float a, float b) {
		if(b>a) {
			this.a = b;
			this.b = a;
		}
		else {
			this.a = a;
			this.b = b;
		}
	}
	
}
