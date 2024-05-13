// Headers
String toString(int);
int toInt(String);
int getValArrayInt(int linha, int coluna, int matriz[], int qtdeLinhas);
bool validaPosicao(String entrada);
int velha;
int linha;
int coluna;
bool haVencedor;
int jogadorDaVez;
int tabuleiro[9];

void zerarTabuleiro(int tabuleiro[9]) {

  haVencedor = false;

  // Limpar/zerar o tabuleiro
  for (int index = 0; index <= 8; index++) {
    tabuleiro[index] = 0;
  }
}


void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // Aguarda a porta serial
  }
}

void loop() {

  // Criar o tabuleiro e jogadores, zerar as variáveis.
  //
  // 0: Posição vazia
  // 1: jogada na Posição do jogador 1
  // 2: jogada na Posição do jogador 2


  // Limpar/zerar o tabuleiro
  zerarTabuleiro(tabuleiro);

  // Iniciar o jogo, definir quem joga primeiro
  int jogadorDaVez = 1;

  // Anotar/Registrar a jogada, do primeiro jogador
  velha = 1;
  do {
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);

    String jogada = "";
    Serial.print("Digite a posicao da sua jogada JOGADOR ");
    Serial.println(jogadorDaVez);
    while (!Serial.available())
      ;

    jogada = Serial.readStringUntil('\n');
    if (validaPosicao(jogada)) {

      // Converter a jogada texto em dois inteiros linha e coluna.
      // Simula a função Serial.parseInt() do Arduino
      linha = jogada.substring(0, 1).toInt();
      coluna = jogada.substring(2, 3).toInt();

      Serial.print("Linha: ");
      Serial.print(linha);
      Serial.print("; Coluna: ");
      Serial.println(coluna);

      // Verificar se a posição 'jogada' é valida
      if (tabuleiro[3 * linha + coluna] == 0) {
        tabuleiro[3 * linha + coluna] = jogadorDaVez;
        if (tabuleiro[0] == jogadorDaVez && tabuleiro[1] == jogadorDaVez && tabuleiro[2] == jogadorDaVez || tabuleiro[3] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[5] == jogadorDaVez || tabuleiro[6] == jogadorDaVez && tabuleiro[7] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
          haVencedor = true;
        } else {

          // Verificar a jogada vencedora nas colunas.
          if (tabuleiro[0] == jogadorDaVez && tabuleiro[3] == jogadorDaVez && tabuleiro[6] == jogadorDaVez || tabuleiro[1] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[7] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[5] == jogadorDaVez && tabuleiro[8] == jogadorDaVez) {
            haVencedor = true;
          } else {

            // Verificar a jogada vencedora nas diagonais.
            if (tabuleiro[0] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[8] == jogadorDaVez || tabuleiro[2] == jogadorDaVez && tabuleiro[4] == jogadorDaVez && tabuleiro[6] == jogadorDaVez) {
              haVencedor = true;
            } else {

              // Trocar o jogador
              jogadorDaVez = (jogadorDaVez == 1) ? 2 : 1;
            }
          }
        }
        velha++;
      } else {
        Serial.println("Posicao ocupada, jogue novamente !!!");

        // Informar ao Jogador 1 que a posição está preenchida, é inválida e ele precisa informar um posição válida.
      }
    } else {
      Serial.println("Jogada inválida !!!");
    }

    // Verificar a jogada vencedora nas linhas.
  } while (!haVencedor && velha <= 9);

  // Verificar o tabuleiro, se houve ganhador ou empate, finalizar o jogo.
  if (haVencedor) {
    Serial.print("Parabens pela a vitoria, jogador ");
    Serial.println(jogadorDaVez);
    delay(5000);
    zerarTabuleiro(tabuleiro);
  } else {
    Serial.println("Deu VELHA!!!");
    delay(5000);
    zerarTabuleiro(tabuleiro);
  }

  Serial.print(tabuleiro[0]);
  Serial.print(tabuleiro[1]);
  Serial.println(tabuleiro[2]);
  Serial.print(tabuleiro[3]);
  Serial.print(tabuleiro[4]);
  Serial.println(tabuleiro[5]);
  Serial.print(tabuleiro[6]);
  Serial.print(tabuleiro[7]);
  Serial.println(tabuleiro[8]);
}

bool validaPosicao(String entrada) {
  bool entradaValida = false;
  if (entrada.length() == 3) {
    if (entrada.charAt(0) == '0' || entrada.charAt(0) == '1' || entrada.charAt(0) == '2') {
      if (entrada.charAt(2) == '0' || entrada.charAt(2) == '1' || entrada.charAt(2) == '2') {
        entradaValida = true;
      }
    }
  }

  return entradaValida;
}
