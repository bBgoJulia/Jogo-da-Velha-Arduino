function main() {
    // criar tabuleiro e jogadores,zerar as variaveis
    // 
    // 0: posição vazia
    // 1: jogada na posição do jogador1
    // 2: jogada na posição do jogador2
    var velha;
    var haVencedor;

    haVencedor = false;
    var tabuleiro = Array(9);
    var linha;
    var coluna;

    // limpar/zerar o tabuleiro
    var index;

    for (index = 0; index <= 8; index++) {
        tabuleiro[index] = 0;
    }
    var jogador1;

    jogador1 = "jogador1";
    var jogador2;

    jogador2 = "jogador2";
    var jogada;

    // iniciar o jogo definir quem joga primeiro
    var jogadordavez;

    jogadordavez = 1;

    // anotar e registrar a jogada do primeiro jogador
    velha = 1;
    do {
    console.log(windtabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
       l(tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
    console.log(tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
    console.log("Digite a posição da sua peça,Jogadordavez");
        jogada = window.prompt('Enter a value for jogada');

        // converter a jogada texto em dois inteiros linha e coluna
        // simula a função Serial.parseint()do Arduino
        linha = parseInt(jogada.charAt(0));
        coluna = parseInt(jogada.charAt(2));
    console.log("linha: " + linha + "; Coluna: " + coluna);

        // verificar se a posição "rodada" é valida
        // converter a jogada texto em dois inteiros linha e coluna
        if (tabuleiro[3 * linha + coluna] == 0) {
            tabuleiro[3 * linha + coluna] = jogadordavez;
        } else {
        console.log("posição ocupada,jogar novamente");

            // informar ao jogador1 que a posição está preenchidaé invalida e ele precisa informar um posição valida
        }

        // verificar o tabuleiro,ce houver ganhador ou empate,finalizar o jogo
        if (tabuleiro[0] == jogadordavez && tabuleiro[1] == jogadordavez && tabuleiro[2] == jogadordavez || tabuleiro[3] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[5] == 1 || tabuleiro[6] == jogadordavez && tabuleiro[7] == 1 && tabuleiro[8] == jogadordavez) {

            // verificar a jogoda vencedora nas linhas
            haVencedor = true;
        } else {
            if (tabuleiro[0] == jogadordavez && tabuleiro[3] == jogadordavez && tabuleiro[6] == jogadordavez || tabuleiro[1] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[7] == 1 || tabuleiro[2] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[6] == jogadordavez) {

                // verificar a jogoda vencedora nas colunas
                haVencedor = true;
            } else {
                if (tabuleiro[0] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[8] == jogadordavez || tabuleiro[2] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[6] == jogadordavez) {

                    // verificar a jogoda vencedora nas diagonais
                    haVencedor = true;
                } else {
                    if (jogadordavez == 1) {
                        jogadordavez = 2;
                    } else {
                        jogadordavez = 1;
                    }
                }
            }
        }
        velha = velha + 1;
    } while (!haVencedor && velha <= 9);
    if (haVencedor) {
    console.log("PARABENS PELA VITORIA JOGADOR" + jogadordavez);
    } else {
    console.log("DEU VELHa");
    }
console.log("parabens você ganhou!");

    // verificar o tabuleiro, se houve ganhador ou empate, finalizar jogo.
}


function validaPosicao(entrada) {
    var entradaValida;

    entradaValida = false;
    console.log(entrada.length);
    if (entrada.length == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
    
    return entradaValida;
}
