/*Botão Pop-up*/
function externo() {
    alert("EXTERNO");
}
var btn_externo = document.getElementById("externo");
btn_externo.addEventListener("click", externo);

/*Botão Console*/
function print_console() {
    console.log("CONSOLE");
}
var bnt_console = document.getElementById("console");
bnt_console.addEventListener("click", print_console);

/*Variáveis*/
console.log("Variáveis")
variavel = "nome"
console.log(typeof (variavel))
variavel = 10
console.log(typeof (variavel))
variavel = ["A", "B", "C"]
console.log(typeof (variavel))

const nome = "Shiva"
console.log(typeof (nome), nome)

/*definição let*/
{
    let nome = "Yoga"
    console.log(nome)
}
console.log(nome)

/*definição var*/
var imortal = "Alan"
console.log(imortal)
{
    var imortal = "Demétrius"
    console.log(imortal)
}
console.log(imortal)

{
    let imortal = "Valejo"
    console.log(imortal)
}
var imortal = 10
console.log(imortal)

/*declaração de funções*/
console.log("Funções")
/*nomeada*/
function quadradoA(x) {
	return x * x
}
console.log(quadradoA(2))

/*anônima*/
const quadradoB = function(x) {
	return x * x
}
console.log(quadradoB(4))

/*arrow function*/
const quadradoC = (x) => {
	return x * x
}
console.log(quadradoB(8))

/*get element by id*/
var el = document.getElementById("idA")
console.log("Elementos por ID")
console.log(el)
console.log(el[0])

/*get elements by class name*/
var el = document.getElementsByClassName("classA")
console.log("Elementos por Classe")
console.log(el[0])
console.log(el[1])
console.log(el[2])

/*get elements by tag name*/
var el = document.getElementsByTagName("p")
console.log("Elementos por Tag")
console.log(el[4])

/*inner html*/
console.log("Inner HTML")
var el = document.getElementById("nome")
var content = el.innerHTML;
console.log(content)

el.innerHTML = "Ulisflávio o Destruidor";
console.log(content)
var content = el.innerHTML;
console.log(content)