/*
 Exercicio 1
 Autor(es): Lucas Santos Souza e Daniel Silva
 Data: 12/07/2021
*/
public class ex3 {
    static class Incubadora{
        private String nome;

        public Incubadora(String startup,int a){
            EmpresaPesquisa empresapesquisa = new EmpresaPesquisa();
            EmpresaInovacao empresainovacao = new EmpresaInovacao();

            StartupA startupa= new StartupA();
        }

        protected void setNomeIncubadora(String nome){
            this.nome = nome;
        }
        protected String getNomeIncubadora(){
            return nome;
        }

        public String toString(){
            return "Incubadora: " + getNomeIncubadora();
        }
    }

    static class EmpresaPesquisa{
        private String nome;
        
        public EmpresaPesquisa(){}
        
        protected void setNomeEmpresaPesquisa(String nome){
            this.nome = nome;
        }
        protected String getNomeEmpresaPesquisa(){
            return nome;
        }

        public String toString(){
            return "EmpresaPesquisa: " + getNomeEmpresaPesquisa();
        }

    }
    static class StartupA{
        private String nome;
        public StartupA(){}
        
        protected void setNomeStartupA(String nome){
            this.nome = nome;
        }
        public StartupA(String nome){
            setNomeStartupA(nome);
        }

        protected String getNomeStartupA(){
            return nome;
        }

        public String toString(){
            return "StartupA:" + getNomeStartupA()+" Empresa:"+getNomeEmpresaPesquisa();
        }
    }
    static class StartupB{
        private String nome;

        protected void setNomeStartupB(String nome){
            this.nome = nome;
        }

        public StartupB(String nome){
            setNomeStartupB(nome);
        }

        protected String getNomeStartupB(){
            return nome;
        }

        public String toString(){
            return "StartupB:" + getNomeStartupB()+" Empresa:"+getNomeEmpresaPesquisa();
        }
    }

    static class EmpresaInovacao{
        private int funcionarios;
        public EmpresaInovacao(){}

        protected void setFuncionariosEmpresaInovacao(int funcionarios){
            this.funcionarios = funcionarios;
        }
        protected int getFuncionariosEmpresaInovacao(){
            return funcionarios;
        }

        public String toString(){
            return "EmpresaInovacao: " + getFuncionariosEmpresaInovacao();
        }
    }
    static class StartupC{
        private String nome;

        protected void setNomeStartupC(String nome){
            this.nome = nome;
        }

        public StartupC(String nome){
            setNomeStartupC(nome);
        }

        protected String getNomeStartupC(){
            return nome;
        }

        public String toString(){
            return "StartupC: " + getNomeStartupC()+"\nQuantidade de funcionario:"+getFuncionariosEmpresaInovacao();
        }
    }
    static class StartupD{
        private String nome;        

        protected void setNomeStartupD(String nome){
            this.nome = nome;
        }
        public StartupD(String nome){
            setNomeStartupD(nome);
        }

        protected String getNomeStartupD(){
            return nome;
        }

        public String toString(){
            return "StartupD: " + getNomeStartupD()+"\nQuantidade de funcionario:"+getFuncionariosEmpresaInovacao();
        }
    } 
    
    
    public class Principal{
        public static void main(String[] args) {
            StartupA objA= new StartupA("Minha nova empresa");
            System.out.println(objA);

            StartupD objD= new StartupD("Sua velha empresa");
            System.out.println(objD);            
        }
    }
    
}
