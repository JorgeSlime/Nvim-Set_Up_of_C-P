" init.vim

" Añadir la ruta a la carpeta 'conf' a 'runtimepath'
set runtimepath+=~/.config/nvim/conf
"set rtp+=~/.vim/autoload/plug.vim

" Cargar archivos de configuración separados
runtime conf/plugins.vim
runtime conf/settings.vim
runtime conf/mappings.vim
runtime conf/theme.vim
runtime conf/commands.vim
"runtime conf/dashboard.vimra habilitar nerdtree
