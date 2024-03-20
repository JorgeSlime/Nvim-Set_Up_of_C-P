call plug#begin('~/.config/nvim/plugged')

" Complemento de coc.nvim
Plug 'neoclide/coc.nvim', {'branch': 'release'}
" complemento nvim-lspconfig
"Plug 'neovim/nvim-lspconfig'
" Mejorado de resaltado de sintaxis de C++
"Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
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
Plug 'bluz71/vim-moonfly-colors', { 'as': 'moonfly' }
Plug 'Murtaza-Udaipurwala/gruvqueen'
Plug 'pineapplegiant/spaceduck', { 'branch': 'main' }
Plug 'voidekh/kyotonight.vim'
Plug 'EdenEast/nightfox.nvim'
Plug 'chriskempson/base16-vim'
Plug 'drewtempelmeyer/palenight.vim'
Plug 'rebelot/kanagawa.nvim'
" Para el árbol de datos NerdTree
Plug 'preservim/nerdtree'
" Para iconos
Plug 'ryanoasis/vim-devicons' " Plugin para mostrar iconos en Nvim
" Para la transparecia
"Plug 'tribela/vim-transparent'
" Configura el nivel de transparencia (un valor entre 0 y 100, donde 0 es completamente opaco)
" Complemento para autocompletado YouCompleteMe
"Plug 'Valloric/YouCompleteMe', {'do': './install.py --clangd-completer'}
" Instalar Telescope
Plug 'nvim-lua/plenary.nvim'
Plug 'nvim-telescope/telescope.nvim', { 'tag': '0.1.1' }
" or                                , { 'branch': '0.1.x' }
Plug 'mhinz/vim-startify'
" Para abrir miniterminal
Plug 'voldikss/vim-floaterm'
" Fin de la lista de complementos

call plug#end()


