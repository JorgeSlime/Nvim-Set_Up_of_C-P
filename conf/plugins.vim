" Complementos de vim-plug
call plug#begin('~/.config/nvim/plugged')

" Complemento de coc.nvim
"Plug 'neoclide/coc.nvim', {'branch': 'release'}
" Mejorado de resaltado de sintaxis de C++
Plug 'octol/vim-cpp-enhanced-highlight'
" Línea de abajo
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
" Auto completado de paréntesis
Plug 'tpope/vim-surround'
Plug 'cohama/lexima.vim'
" Guías de indentación
Plug 'lukas-reineke/indent-blankline.nvim'
" Pluggins de temas
Plug 'marko-cerovac/material.nvim'
Plug 'morhetz/gruvbox'
Plug 'lighthaus-theme/vim-lighthaus'
Plug 'joshdick/onedark.vim'
Plug 'tomasr/molokai'
" Tranparencia a los temas
Plug 'xiyaowong/nvim-transparent'
" Para el árbol de datos NerdTree
Plug 'preservim/nerdtree'
" Para iconos
Plug 'ryanoasis/vim-devicons' " Plugin para mostrar iconos en Nvim

" Complemento para autocompletado YouCompleteMe
Plug 'Valloric/YouCompleteMe', {'do': './install.py --clangd-completer'}

" Fin de la lista de complementos
call plug#end()

