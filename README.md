# Processador</h1>
Este projeto implementa um simulador de processador de dois núcleos que utilizam o Scoreboarding. Apresentado e desenvolvido durante a disciplina de Arquitetura e Organização de Computadores II.

# Comandos suportados
Atualmente, o Scoreboarding suporta as seguintes operações:
* li
* move
* add
* addi
* sub
* or
* ori
* and
* andi
* slt
* mult
* div

Os comandos li e move são comandos extras colocados no simulador. Eles seguem a sintáxe descrita no [GreenCard](https://inst.eecs.berkeley.edu/~cs61c/resources/MIPS_Green_Sheet.pdf).

# Como usar
Para executar o simulador, são necessários os parâmetros ***-c configFile***, ***-o outputFile1***, ***-p programFile1***, ***-m memoryLength1***, ***-i outputFile2***, ***-r programFile2*** e ***-n memoryLength2***.

ConfigFile representa o arquivo contendo as latências de cada uma das instruções (todos as instruções devem ter suas latências declaradas aqui).

OutputFile1 representa o nome do arquivo de saída do primeiro programa, onde será impresso o resultado *clock a clock* da simulação.

ProgramFile1 representa o arquivo contendo o código em Assembly do primeiro programada que será lido pelo simulador. Este deve respeitas as convenções do MIPS32, descritas em [GreenCard](https://inst.eecs.berkeley.edu/~cs61c/resources/MIPS_Green_Sheet.pdf), e estar de acordo com os comandos que são usados aqui.

MemoryLength1 representa o tamanho que será alocado para o primeiro programa que será executado. O tamanho é um número inteiro e deve ser igual ou menor à quantidade de linhas no código Assembly.

OutputFile2 representa o nome do arquivo de saída do segundo programa, onde será impresso o resultado *clock a clock* da simulação.

ProgramFile2 representa o arquivo contendo o código em Assembly do segundo programada que será lido pelo simulador. Este deve respeitas as convenções do MIPS32, descritas em [GreenCard](https://inst.eecs.berkeley.edu/~cs61c/resources/MIPS_Green_Sheet.pdf), e estar de acordo com os comandos que são usados aqui.

MemoryLength2 representa o tamanho que será alocado para o segundo programa que será executado. O tamanho é um número inteiro e deve ser igual ou menor à quantidade de linhas no código Assembly.