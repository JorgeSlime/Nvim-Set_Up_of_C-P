"a habilitar nerdtreeappings
"Para habilitar nerdtree
nnoremap <silent> <C-q> :NERDTreeToggle<CR> 
"Cambiar entre ventanas 
nnoremap <silent> <C-l> :tabnext<CR>
nnoremap <silent> <C-h> :tabprevious<CR>
"Para cerrar ventanas
"nnoremap <silent> <C-w> :tabclose<CR>
"para abrir nuevas ventanas
nnoremap <silent> <C-n> :tabnew<CR> 
nnoremap <silent> <C-r> :call CompileProgram()<CR>
"nnoremap <silent> <C-b> :call RunProgram()<CR>
"para copiar todo
map <C-a> <esc>ggVG<CR> 
" visual block 
nnoremap <C-z> <C-v>
" Mapeo personalizado para abrir Telescope
nnoremap <C-f> <cmd>Telescope find_files<cr>
"poner le clasico Ctrl-c para copiar al portapapeles
vnoremap <C-c> "+y
"poner el Template.cpp con hora actualizada cada segundo
"nnoremap <silent> <C-m> :call UpdateTimestamps()<CR>
command! Z17 :execute UpdateTimestamps17()
command! Z11 :execute UpdateTimestamps11()
command! Z17IO :execute UpdateTimestamps17IO()
" Comando para crear un nuevo archivo .cpp y actualizar las marcas de tiempo
command! Basic   :execute "0r ~/.config/nvim/Library/My_Templates/Basic.cpp"
command! Basic11 :execute "0r ~/.config/nvim/Library/My_Templates/Basic11.cpp" 
command! Basic17 :execute "0r ~/.config/nvim/Library/My_Templates/Basic17.cpp"
"command! -nargs=1 RunProgram :w<bar>!bash /ruta/al/script.sh <args><bar>redraw!
command! XD :execute RunProgramI()
command! XDD :execute RunProgramIO2('input.txt')
command! INPUT :execute OpenInput()

" Comando para abrir una terminal flotante
nnoremap <silent> <C-t> :FloatermToggle<CR>
" Mapeo para copiar al portapapeles (xclip)
"vnoremap <C-x> :!xclip -selection clipboard -i<CR>

" Mapeo para pegar desde el portapapeles (xclip)
"nnoremap <C-v> :r!xclip -selection clipboard -o<CR>
" Mapeos para compilar y ejecutar programas Java
"nnoremap <F10> :call CompileAndRunJavaProgram()<CR>
" Mapeos para compilar y ejecutar programas Python
"nnoremap <F9> :call CompileAndRunPythonProgram()<CR>

" Mapeo para compilar y ejecutar programas en Python o C++
nnoremap <silent> <C-b> :call CompileAndRunProgram()<CR>
" Mapeo para compilar con input.txt solo c++ 
nnoremap <silent> <C-M-b> :call RunProgramIO('input.txt')<CR>
"Mapeo para habilitar tabular en opciones de autocompletado para Coc
"inoremap <expr> <Tab> pumvisible() ? "\<C-n>" : "\<Tab>"
"COC SNIPPETS 
" Use <C-l> for trigger snippet expand.
imap <C-l> <Plug>(coc-snippets-expand)
imap <CR> <Plug>(coc-snippets-expand)
" Use <C-j> for select text for visual placeholder of snippet.
vmap <C-j> <Plug>(coc-snippets-select)

" Use <C-j> for jump to next placeholder, it's default of coc.nvim
let g:coc_snippet_next = '<c-j>'

" Use <C-k> for jump to previous placeholder, it's default of coc.nvim
let g:coc_snippet_prev = '<c-k>'

" Use <C-j> for both expand and jump (make expand higher priority.)
imap <C-j> <Plug>(coc-snippets-expand-jump)

" Use <leader>x for convert visual selected code to snippet
xmap <leader>x  <Plug>(coc-convert-snippet)
"Mapeo para algoritms
"FUNCION Z
    command! AfuncionZ :execute "r ~/.config/nvim/Library/My_Algorithms/Z_funcion.cpp" 
"UNION_FIND 
    command! AUnionFind :execute "r ~/.config/nvim/Library/My_Algorithms/DSU.cpp"
"BIT
    command! AFenwickTree :execute "r ~/.config/nvim/Library/My_Algorithms/BIT.cpp"
"criba_de_erastosthenes
    command! Acriba :execute "r ~/.config/nvim/Library/My_Algorithms/Criba_Of_Erastothenes.cpp"
"BinPowMOD
    command! ABinpowMOD :execute "r ~/.config/nvim/Library/My_Algorithms/BinpowMOD.cpp"
"BinPow
    command! ABinpow :execute "r ~/.config/nvim/Library/My_Algorithms/Binpow.cpp"
"Binary_search
    command! ABinarySearch :execute "r ~/.config/nvim/Library/My_Algorithms/Binary_Serch.cpp"
"KMP
    command! AKmp :execute "r ~/.config/nvim/Library/My_Algorithms/KMP.cpp"
"Bfs
    command! ABfs :execute "r ~/.config/nvim/Library/My_Algorithms/BFS.cpp"
"BFS_Lambda
    command! ABfsLambda :execute "r ~/.config/nvim/Library/My_Algorithms/BFS_Lambda.cpp"
"Dijkstra"
    command! ADijkstraT :execute "r ~/.config/nvim/Library/My_Algorithms/Dijkstra_T.cpp"
"__int128
    command! Ai128 :execute "r ~/.config/nvim/Library/My_Algorithms/i128.cpp"
"Prefix_sum
    command! APrefix :execute "r ~/.config/nvim/Library/My_Algorithms/prefix_sum.cpp"
"Stable Sort
    command! ASort :execute "r ~/.config/nvim/Library/My_Algorithms/sort.cpp"
" Segment Tree
    command! ASegmentTree :execute "r ~/.config/nvim/Library/My_Algorithms/Segment_Tree.cpp"
" contar reps por poscicion 
    command! ACntTable :execute "r ~/.config/nvim/Library/My_Algorithms/cnt_table.cpp"
" Sparse Table
    command! ASparseTable :execute "r ~/.config/nvim/Library/My_Algorithms/Sparse_Table.cpp"
" INFs
    command! AINFT :execute "r ~/.config/nvim/Library/My_Algorithms/INF.cpp"
" DEBUGGER  
    command! ADEBBUGER :execute "r ~/.config/nvim/Library/My_Algorithms/templateF/debugger.cpp"
" YES OR NO 
    command! AYES :execute "r ~/.config/nvim/Library/My_Algorithms/templateF/YES.cpp"
