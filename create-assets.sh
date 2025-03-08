#!/bin/bash

# Cria diretório de assets se não existir
mkdir -p assets

# Cria imagem SVG para o personagem feliz
cat > assets/happy.svg << EOF
<svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">
  <circle cx="100" cy="100" r="80" fill="#FFD700" stroke="#000" stroke-width="2"/>
  <circle cx="70" cy="80" r="10" fill="#000"/>
  <circle cx="130" cy="80" r="10" fill="#000"/>
  <path d="M60 120 Q100 150 140 120" stroke="#000" stroke-width="4" fill="none"/>
</svg>
EOF

# Cria imagem SVG para o personagem triste
cat > assets/sad.svg << EOF
<svg width="200" height="200" xmlns="http://www.w3.org/2000/svg">
  <circle cx="100" cy="100" r="80" fill="#FFD700" stroke="#000" stroke-width="2"/>
  <circle cx="70" cy="80" r="10" fill="#000"/>
  <circle cx="130" cy="80" r="10" fill="#000"/>
  <path d="M60 140 Q100 110 140 140" stroke="#000" stroke-width="4" fill="none"/>
</svg>
EOF

# Instrução para instalar ferramentas necessárias
echo "Por favor, instale as dependências necessárias:"
echo "sudo apt-get install librsvg2-bin fonts-freefont-ttf"
echo ""

# Converte SVGs para PNGs
echo "Convertendo imagens SVG para PNG..."
if command -v rsvg-convert &> /dev/null; then
    rsvg-convert -h 200 assets/happy.svg > assets/happy.png
    rsvg-convert -h 200 assets/sad.svg > assets/sad.png
    echo "Imagens convertidas com sucesso."
else
    echo "AVISO: rsvg-convert não encontrado. Execute 'sudo apt-get install librsvg2-bin' para instalá-lo."
    echo "Você precisará converter manualmente os arquivos SVG para PNG."
fi

# Copia uma fonte TTF para a pasta de assets
if [ -f "/usr/share/fonts/truetype/freefont/FreeSans.ttf" ]; then
    cp /usr/share/fonts/truetype/freefont/FreeSans.ttf assets/arial.ttf
    echo "Fonte copiada com sucesso."
else
    echo "AVISO: Fonte FreeSans.ttf não encontrada."
    echo "Você precisará copiar manualmente um arquivo de fonte TTF para assets/arial.ttf"
fi

echo ""
echo "Configuração de assets concluída."