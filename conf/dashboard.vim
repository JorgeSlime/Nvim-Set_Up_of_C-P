" dashboard.vim

" Limpia la pantalla
autocmd VimEnter * silent! colorscheme default | silent! filetype plugin indent off | silent! syntax off | silent! set noswapfile | silent! set nobackup | silent! set noundofile | silent! set nowrap

" Define la función para mostrar el dashboard
function! ShowDashboard()
    " Limpia el buffer actual y carga el ASCII art
    silent! %bwipeout!
    silent! 0read ~/.config/nvim/ascii.txt

    " Configuraciones adicionales de tu dashboard
    " ...

    " Mueve el cursor a la primera línea
    1

    " Desactiva la línea de estado
    set laststatus=0
endfunction

" Muestra el dashboard al iniciar Neovim
autocmd VimEnter * call ShowDashboard()

