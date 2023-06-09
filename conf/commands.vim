"Commands

" Configuración para coc.nvim
let g:coc_global_extensions = ['coc-clangd']
" Configuración adicional para C++
autocmd FileType cpp setlocal omnifunc=coc#refresh()



"Comando para autocargar mi template en un archivo c++
autocmd BufNewFile *.cpp 0r /home/jorgeslime/CP/Library/Template.cpp

"comando para copiar en el portapapeles de W11
if has('clipboard')
  set clipboard+=unnamedplus
endif
vnoremap <C-c> "+y "suplanta al +y por C-c

"Funcions
"CONMPILE C++
function! CompileProgram()
    let program_name = expand('%:r')
    let compile_command = 'g++ -std=c++17 -O2 -Wall -Wextra -o ' . program_name . ' ' . expand('%')

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
"RUN C++
function! RunProgram()
    let program_name = expand('%:r')
    let run_command = './' . program_name

    " Ejecutar el programa en una ventana a la izquierda o en una división vertical
    leftabove vsplit term://./%:r
    execute 'terminal ' . run_command
    startinsert
endfunction
