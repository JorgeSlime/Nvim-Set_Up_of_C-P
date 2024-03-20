"Commands

" Configuración adicional para C++
autocmd FileType cpp setlocal omnifunc=coc#rpc#request
" Configuración para coc.nvim
let g:coc_global_extensions = ['coc-clangd']
"configuracion de yoycompleteme
"let g:ycm_python_binary_path = '/ruta/a/python3.11'
" Configuración de nvim-treesitter
lua <<EOF
require'nvim-treesitter.configs'.setup {
    ensure_installed = {
        "c",
        "cpp"
    },
    highlight = {
        enable = true -- Habilitar resaltado de sintaxis usando Tree-sitter
    }
}
EOF
"Abrir achivo input
function! OpenInput()
    " Abrir el archivo input.txt en una nueva ventana vertical
   vsplit input.txt
endfunction

" Función para actualizar las marcas de tiempo en el archivo actual
function! UpdateTimestamps17()
    let l:created = 'Created: ' . strftime('%d.%m.%Y')
    let l:time = 'Time: ' . strftime('%H.%M.%S')

    " Elimina las líneas con "Created:" o "Time:" seguido de cualquier texto
    execute ':%g/^\s*\(Created\|Time\):\s.*$/d'

    " Agrega las nuevas marcas de tiempo desde la plantilla
    execute '0r ~/.config/nvim/Library/My_Templates/Template.cpp'

    " Busca las líneas en blanco y reemplaza por las marcas de tiempo
    execute ':%s/^\s*Created:\s*$/\1 ' . l:created
    execute ':%s/^\s*Time:\s*$/\1 ' . l:time
endfunction
" Función para actualizar las marcas de tiempo en el archivo actual
function! UpdateTimestamps11()
    let l:created = 'Created: ' . strftime('%d.%m.%Y')
    let l:time = 'Time: ' . strftime('%H.%M.%S')

    " Elimina las líneas con "Created:" o "Time:" seguido de cualquier texto
    execute ':%g/^\s*\(Created\|Time\):\s.*$/d'

    " Agrega las nuevas marcas de tiempo desde la plantilla
    execute '0r ~/.config/nvim/Library/My_Templates/T11.cpp'

    " Busca las líneas en blanco y reemplaza por las marcas de tiempo
    execute ':%s/^\s*Created:\s*$/\1 ' . l:created
    execute ':%s/^\s*Time:\s*$/\1 ' . l:time
endfunction
function! UpdateTimestamps17IO()
    let l:created = 'Created: ' . strftime('%d.%m.%Y')
    let l:time = 'Time: ' . strftime('%H.%M.%S')

    " Elimina las líneas con "Created:" o "Time:" seguido de cualquier texto
    execute ':%g/^\s*\(Created\|Time\):\s.*$/d'

    " Agrega las nuevas marcas de tiempo desde la plantilla
    execute '0r ~/.config/nvim/Library/My_Templates/TemplateFastIO.cpp'

    " Busca las líneas en blanco y reemplaza por las marcas de tiempo
    execute ':%s/^\s*Created:\s*$/\1 ' . l:created
    execute ':%s/^\s*Time:\s*$/\1 ' . l:time
endfunction

"Comando para autocargar mi template en un archivo c++
"autocmd BufNewFile *.cpp 0r /home/jorgeslime/CP/Library/Template.cpp

"comando para copiar en el portapapeles de W11
"if has('clipboard')
"  set clipboard+=unnamedplus
"endif

" Compilar y ejecutar programas en Python o C++
function! CompileAndRunProgram()
    let file_extension = expand('%:e')
    let program_name = expand('%:r')

    if file_extension ==# 'py'
        " Archivo Python: Ejecutar con Python
        let run_command = 'python3 ' . expand('%')
    elseif file_extension ==# 'cpp'
        " Archivo C++: Ejecutar sin compilar
        let run_command = './' . program_name
    else
        echohl ErrorMsg
        echo 'Tipo de archivo no compatible.'
        echohl None
        return
    endif

    " Ejecutar el programa en una ventana a la izquierda o en una división vertical
    leftabove vsplit term://./%:r
    execute 'terminal ' . run_command
    startinsert
endfunction

" Compilar y ejecutar programas en Python
function! CompileAndRunPythonProgram()
    let program_name = expand('%:r')

    " Comprueba si el archivo tiene extensión .py
    if expand('%:e') == 'py'
        " Compilar y ejecutar el programa Python
        let run_command = 'python ' . expand('%')
        execute 'terminal ' . run_command
        startinsert
    else
        echohl ErrorMsg
        echo 'Este archivo no es un programa Python válido.'
        echohl None
    endif
endfunction
"Funcions
"CONMPILE C++
function! CompileProgram()
    let program_name = expand('%:r')
    let compile_command = 'g++ -std=c++20 -O2 -Wall -Wextra -Wunknown-pragmas -o ' . program_name . ' ' . expand('%')

    " Compilar el programa
    let compile_output = systemlist(compile_command)

    " Verificar si hubo errores de compilación
    if v:shell_error
        echohl ErrorMsg
        echo 'Error de compilación:'
        for error_line in compile_output
            echo error_line
        endfor
        echohl None
    else
        echo 'Programa compilado correctamente'
    endif
endfunction
"COMPILAR ABRIENDO TERMINAL EXTERNA 'TILIX' ES LA TERMINAL ES ESTE CASO
function! RunProgramI()
    " Obtener el nombre del programa compilado
    let program_name = expand('%:r')

    " Generar el comando para ejecutar el programa compilado en una nueva terminal
    let run_command = 'tilix -e /bin/bash -c "./' . program_name . '; echo; read -p ''Pulse_intro_para_salir...''"'

    " Ejecutar el comando en el sistema
    call system(run_command)
endfunction
"COMPILAR ABRIENDO TERMINAL EXTERNA 'TILIX' ES LA TERMINAL ES ESTE CASO con
"parametro de archivo '<'
function! RunProgramIO2(input_file)
    " Compilar el programa
    "call CompileProgram()

 " Obtener el nombre del programa compilado
    let program_name = expand('%:r')

    " Generar el comando para ejecutar el programa con el archivo de entrada en una nueva terminal
    let run_command = 'tilix -e "/bin/bash -c \"./' . program_name . ' < ' . a:input_file . '; echo; read -p ''Pulse_intro_para_salir...''\""'

    " Ejecutar el comando en el sistema
    call system(run_command)
endfunction


"RUN simple C++
function! RunProgram()
    let program_name = expand('%:r')
    let run_command = './' . program_name

    " Ejecutar el programa en una ventana a la izquierda o en una división vertical
    leftabove vsplit term://./%:r
    execute 'terminal ' . run_command
    startinsert
endfunction
"RUN SIMPLE C++ WITH input.txt '<'
function! RunProgramIO(input_file)
    let program_name = expand('%:r')
    let run_command = './' . program_name . ' < ' . a:input_file

    " Ejecutar el programa en una ventana a la izquierda o en una división vertical
    leftabove vsplit term://./%:r
    execute 'terminal ' . run_command
    startinsert
endfunction


"Configurción NERD TREE

" Ocultar línea de indentación
let g:NERDTreeIndentMarkers = 0

" Mostrar íconos para archivos y directorios
let g:NERDTreeDirArrowExpandable = '▸'
let g:NERDTreeDirArrowCollapsible = '▾'
let g:NERDTreeIconGlyphPadding = 1

" Resaltar el archivo actualmente abierto
highlight NERDTreeCWD gui=bold guifg=Yellow

" Mostrar siempre NERDTree al iniciar Vim
"autocmd VimEnter * NERDTree
"ver archivos ocultos
let g:NERDTreeShowHidden = 1
"abrir documetos en una nueva pestaña
let g:NERDTreeMapOpenInTab = '<C-e>'

" Configuración de vim-startify
let g:startify_custom_header = [
  \ '                                  ______   __        ______  __       __  ________  __     __  ______  __       __ ',
  \ '                                 /      \ |  \      |      \|  \     /  \|        \|  \   |  \|      \|  \     /  \',
  \ '                                |  $$$$$$\| $$       \$$$$$$| $$\   /  $$| $$$$$$$$| $$   | $$ \$$$$$$| $$\   /  $$',
  \ '                                | $$___\$$| $$        | $$  | $$$\ /  $$$| $$__    | $$   | $$  | $$  | $$$\ /  $$$',
  \ '                                 \$$    \ | $$        | $$  | $$$$\  $$$$| $$  \    \$$\ /  $$  | $$  | $$$$\  $$$$',
  \ '                                 _\$$$$$$\| $$        | $$  | $$\$$ $$ $$| $$$$$     \$$\  $$   | $$  | $$\$$ $$ $$',
  \ '                                |  \__| $$| $$_____  _| $$_ | $$ \$$$| $$| $$_____    \$$ $$   _| $$_ | $$ \$$$| $$',
  \ '                                 \$$    $$| $$     \|   $$ \| $$  \$ | $$| $$     \    \$$$   |   $$ \| $$  \$ | $$',
  \ '                                  \$$$$$$  \$$$$$$$$ \$$$$$$ \$$      \$$ \$$$$$$$$     \$     \$$$$$$ \$$      \$$',
  \ '                                                                                                               ',
  \ '                                                                                                               ',
  \ '                                                                                                               '
  \ ]
" Configurar el pie de página personalizado
let g:startify_custom_footer = [
  \ '',
  \ '        For more information, check out the Neovim documentation:',
  \ '                   :help nvim',
  \ '',
  \ '                 Happy Vimming!   🚀',
  \ ]

" Configurar la lista de archivos personalizada
let g:startify_lists = [
  \ { 'type': 'sessions', 'header': ['   Sessions'] },
  \ { 'type': 'files', 'header': ['   Files'] },
  \ { 'type': 'bookmarks', 'header': ['   Bookmarks'] },
  \ { 'type': 'commands', 'header': ['   Commands'] },
  \ ]

" Configurar el título personalizado
let g:startify_custom_indices = [
  \ '        Recently Used Files',
  \ '        Projects',
  \ '        Bookmarks',
  \ '        Commands',
  \ ]

" Configurar el color del encabezado y pie de página
highlight StartifyHeader guifg=#ff8800 guibg=NONE gui=bold
highlight StartifyFooter guifg=#aaaaaa guibg=NONE

" Configurar el color de la lista de archivos
highlight StartifyFile guifg=#cccccc guibg=NONE

" Configurar el color del título
highlight StartifyNumber guifg=#ffffff guibg=NONE

" Configurar el color del cursor en la lista de archivos
highlight StartifySelection guifg=#000000 guibg=#ff8800 gui=bold

" Configurar el color del cursor en el título
highlight StartifySelectionTitle guifg=#ffffff guibg=#ff8800 gui=bold

" Configurar el color de los encabezados de sección
highlight StartifySection guifg=#ff8800 guibg=NONE gui=bold

" Configurar el color de los encabezados de sección resaltados
highlight StartifySectionTitle guifg=#ffffff guibg=#ff8800 gui=bold

"conf vim airline
" Configuración minimalista de Vim Airline
let g:airline#extensions#tabline#enabled = 1 " Mostrar pestañas
let g:airline#extensions#tabline#formatter = 'unique_tail_improved'
let g:airline#extensions#tabline#buffer_idx_mode = 1 " Mostrar índice de buffer en lugar de número de pestaña
let g:airline#extensions#tabline#tab_nr_type = 1 " Mostrar el número de pestaña en lugar del nombre del buffer
let g:airline_powerline_fonts = 1 " Habilitar fuentes Powerline para símbolos
" Configuración de los segmentos
" "let g:airline_section_a = '%{bufname("%")}'
let g:airline_section_b = '%{strftime("%H:%M")}'
"let g:airline_section_c = '%{getcwd()}'
"let g:airline_section_x = '' " Sección x vacía
"let g:airline_section_y = '' " Sección y vacía
"let g:airline_section_z = '' " Sección z vacía



