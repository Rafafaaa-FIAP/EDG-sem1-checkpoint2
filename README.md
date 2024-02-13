<h1 align="center">Ano 1 - Semestre 1 - Checkpoint 2 - 1ESPR</h1>

<hr/>

<p align="center">
  <a href="#pushpin-Introdução">Introdução</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#bulb-Desafio">Desafio</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#hammer_and_wrench-Tecnologias">Tecnologias</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#desktop_computer-Simulador">Simulador</a>
</p>

<hr/>

## :pushpin: Introdução
A Vinheria Agnello precisa monitorar as condições de temperatura, umidade e luminosidade do ambiente onde armazena os vinhos para não haver perca de qualidade dos produtos.

## :bulb: Desafio
### LED
<ul>
  <li>Enquanto o ambiente estiver escuro, o LED Verde deve ficar aceso;</li>
  <li>Enquanto o ambiente estiver a meia luz, o LED amarelo deve ficar aceso e mensagem de “Ambiente a meia luz” deve ser mostrado no Display;</li>
  <li>Enquanto o ambiente estiver totalmente iluminado, o LED vermelho deve ficar aceso e a mensagem “Ambiente muito claro” deve ser mostrado no display.</li>
</ul>

### Temperatura
<ul>
  <li>Enquanto o ambiente estiver com uma temperatura entre 10°C e 15°C, o Display deve informar “Temperatura OK” e também mostrar o valor da temperatura;</li>
  <li>Enquanto a temperatura estiver fora da faixa ideal, o Display deve informar “Temp. Alta”, para valores acima de 15°C e também mostrar a temperatura;</li>
  <li>Enquanto a temperatura estiver fora da faixa ideal, o Display deve informar “Temp. Baixa”, para valores abaixo de 10°C e também mostrar a temperatura.</li>
</ul>

### Umidade
<ul>
  <li>Enquanto o ambiente estiver com uma umidade entre 60% e 80%, o Display deve informar “Umidade OK”, e também mostrar o valor da umidade;</li>
  <li>Enquanto a umidade estiver fora da faixa ideal, o Display deve informar “Umidade. Alta”, para valores acima de 70% e também mostrar a umidade;</li>
  <li>Enquanto a umidade estiver fora da faixa ideal, o Display deve informar “Umidade. Baixa”, para valores abaixo de 50% e também mostrar a umidade.</li>
</ul>

### Geral
<ul>
  <li>Para os casos de Temperatura Baixa e Umidade Baixa, o Buzzer deve ficar ligado por 3 segundos e desligado por 3 segundos;</li>
  <li>Para os casos de Temperatura Alta e Umidade Alta, o Buzzer deve ficar ligado Continuamente;</li>
  <li>Os valores apresentados no display devem ser a média de pelo menos 5 leituras dos sensores, e os valores devem ser apresentad os a cada 5 segundos.</li>
</ul>

## :hammer_and_wrench: Tecnologias e Ferramentas
Este projeto utilizou as seguintes tecnologias e ferramentas:
* [Wokwi](https://wokwi.com/)
* [C++](https://pt.wikipedia.org/wiki/C%2B%2B)

## :desktop_computer: Simulador
Foi feito no simulador do [Wokwi](https://wokwi.com/) o circuito para realização dos teste necessários, facilitando no momento da montagem do circuito físico.
<br/><br/>
<a href="https://wokwi.com/projects/378149597869460481" target="_blank">
  <img src="https://github.com/studies2023-FIAP-ES-553521-ano1-05-EDG/Checkpoint-2/blob/main/circuit.png" alt="circuit" />
</a>
<h6>Veja o circuito clicando na imagem e veja o vídeo explicativo clicando <a href="https://drive.google.com/file/d/1pAHMPnv_nKahRPtLDKXdmldR5bdx1104/view?usp=sharing">aqui.</a></h6>
