# Inputchi

Inputchi é um aplicativo interativo que monitora seus toques de teclado e os converte em "comida" para um personagem virtual. O personagem ficará feliz enquanto for alimentado regularmente, mas ficará triste se ficar com fome.

## Sobre o Projeto

Inputchi é inspirado nos conceitos de "pets virtuais" como Tamagotchi. Ele monitora a atividade do seu teclado e utiliza essa entrada para "alimentar" o personagem. A cada `KEYS_TO_FOOD_CONVERSION_FACTOR` teclas pressionadas, um ponto de comida é gerado. O personagem consome um ponto de comida a cada `TIME_TO_EAT` segundos (definido como 60 segundos por padrão).

## Requisitos do Sistema

- Sistema Linux (para acesso aos eventos de entrada)
- G++ com suporte a C++11
- Biblioteca SFML para a interface gráfica
- Utilitários para recursos gráficos (opcional):
  - librsvg2-bin (para conversão de SVG para PNG)
  - fonts-freefont-ttf (para fontes)

## Instalação

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/inputchi.git
   cd inputchi
   ```

2. Instale as dependências:
   ```bash
   sudo apt-get install libsfml-dev librsvg2-bin fonts-freefont-ttf
   ```

3. Prepare os arquivos de assets:
   ```bash
   chmod +x create-assets.sh
   ./create-assets.sh
   ```

4. Compile o projeto:
   ```bash
   make
   ```

## Uso

Inputchi pode ser executado em dois modos: interface de linha de comando (CLI) ou interface gráfica (GUI).

### Modo CLI (padrão)

```bash
./bin/inputchi
```

### Modo GUI

```bash
./bin/inputchi --gui
# ou
./bin/inputchi -g
```

## Personalização

Você pode personalizar vários aspectos do Inputchi editando as definições no arquivo `include/inputchi/inputchi.h`:

- `TIME_TO_EAT`: tempo em segundos entre cada refeição do personagem (padrão: 60)
- `KEYS_TO_FOOD_CONVERSION_FACTOR`: número de teclas necessárias para gerar um ponto de comida (padrão: 250)

### Dispositivo de Entrada

Por padrão, o Inputchi monitora o dispositivo `/dev/input/event3`. Você pode precisar ajustar isto no arquivo `src/inputchi.cpp` para corresponder ao seu teclado:

```cpp
int fd = open("/dev/input/event3", O_RDONLY);
```

Para identificar o dispositivo correto, você pode usar:

```bash
sudo cat /proc/bus/input/devices
```

## Estrutura do Projeto

- `include/`: Arquivos de cabeçalho
  - `inputchi/`: Namespace do projeto
    - `hud.h`: Interface de linha de comando
    - `inputchi.h`: Definições principais
    - `signal_handler.h`: Tratamento de sinais
    - `gui.h`: Interface gráfica
- `src/`: Arquivos de código-fonte
  - `hud.cpp`: Implementação da interface de linha de comando
  - `inputchi.cpp`: Lógica principal do programa
  - `main.cpp`: Ponto de entrada do programa
  - `signal_handler.cpp`: Implementação do tratamento de sinais
  - `gui.cpp`: Implementação da interface gráfica
- `assets/`: Recursos visuais (imagens e fontes)
- `bin/`: Executáveis compilados
- `obj/`: Arquivos objeto da compilação

## Solução de Problemas

### Permissões de Dispositivo de Entrada

Se você receber um erro ao abrir o dispositivo de entrada, verifique as permissões:

```bash
sudo chmod a+r /dev/input/event*
```

Para uma solução permanente, crie uma regra udev:

```bash
echo 'KERNEL=="event*", NAME="input/%k", MODE="0664", GROUP="input"' | sudo tee /etc/udev/rules.d/99-input.rules
sudo usermod -a -G input $USER
```

### Conversão de Imagens

Se o script `create-assets.sh` não conseguir converter as imagens SVG para PNG, você pode:
1. Instalar as ferramentas necessárias: `sudo apt-get install librsvg2-bin`
2. Converter manualmente: `rsvg-convert -h 200 assets/happy.svg > assets/happy.png`

## Recursos Adicionais

- [Documentação da SFML](https://www.sfml-dev.org/documentation/2.5.1/)
- [API de Entrada do Linux](https://www.kernel.org/doc/html/latest/input/input.html)

## Licença

Este projeto está licenciado sob a licença MIT - veja o arquivo LICENSE para detalhes.