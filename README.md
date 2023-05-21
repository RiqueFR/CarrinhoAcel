# CarrinhoAcel

Este projeto consiste no projeto de um robô/carrinho controlado remotamente por meio de comunicação Bluetooth e os dados lidos de um acelorômetro, que foi preso a uma luva sendo assim responsável por direcionar o robô conforme a inclinação da mão do condutor.</br>
O projeto foi desenvolvido para a disciplina de Projeto Integrado de Computação, no segundo período do curso de Engenharia de Computação da UFES.

## Esquemático

No diretório "Esq_Eagle" é possível encontrar o esquemático eletrônico desenvolvido tanto para a luva quanto para o carrinho, em seus respectivos diretórios.

## Funcionamento

O projeto funciona basicamente da seguinte forma, um Arduíno lê os dados do sensor de acelerômetro, transforma esses dados em uma direção, representada por um caractér, e um valor entre 0 e 1, que representa o quão inclinada está a luva.
Esses dado são passados via Bluetooth para outro Arduíno que está no robô, e ele controla a velocidade dos motores de acordo com a direção e o decimal recebido, que representa uma porcentagem da velocidade dele.

## Outros

É possível ver mais informações do projeto no documento "Henrique_Thiago_Henrique.pdf", que foi o arquivo enviado como relatório para o professor da disciplina.
