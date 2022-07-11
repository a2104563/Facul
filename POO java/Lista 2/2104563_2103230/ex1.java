/*
 Exercicio 1
 Autor(es): Lucas Santos Souza e Daniel Silva
 Data: 12/07/2021
*/
public class ex1{  
    
    static public class DataCompra{
        private int dia;
        private int mes;
        private int ano;
        
        public DataCompra(int d, int m, int a) {            
            this.dia = ( (d>=1 && d<=31)? d:1);
            this.mes = ( (m>=1 && m<=12)? m:1);
            this.ano = ( (a>=1)? a:1);
        }        
        public String toString(){            
            return this.dia + " , " + this.mes + " , " + this.ano;
        }

    }

    static public class Computador {
        private String nome;
        private String modelo;
        private DataCompra dataCompra;

        public Computador setDataCompra(int d, int m, int a){
            dataCompra= new DataCompra(d, m, a);
            return this;
        }        

        public Computador(){}

        protected void setNome(String nome){
            this.nome = nome;
        }
        protected void setModelo(String modelo){
            this.modelo = modelo;
        }

        protected String getNome(){
            return nome;
        }
        protected String getModelo(){
            return nome;
        }

        public String toString(){
            return getNome();
        }
    }

    static public class Desktop extends Computador{
        public Desktop(String nome){
            setNome(nome);
        }

        public String toString(){
            return getNome()+getModelo();
        }
    }

    static public class Celular extends Computador{
        public Celular(String nome){
            setNome(nome);
        }

        public String toString(){
            return getNome()+getModelo();
        }
    }

    public class Principal {

        public static void main(String[] args) {
            Desktop d= new Desktop("comp1");
            Celular c= new Celular("cel1"); 
            
            d.setModelo("Intel");
            d.setDataCompra(10, 10, 1998);

            c.setModelo("Samsung");
            c.setDataCompra(9, 9, 1999);

            System.out.println(d.getModelo());
            System.out.println(c.getModelo());             
            
        }     
    }
}

