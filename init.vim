" init.vim

" Añadir la ruta a la carpeta 'conf' a 'runtimepath'
set runtimepath+=~/.config/nvim/conf

" Cargar archivos de configuración separados
runtime conf/plugins.vim
runtime conf/settings.vim
runtime conf/mappings.vim
runtime conf/theme.vim
runtime conf/commands.vim
"runtime conf/dashboard.vim
