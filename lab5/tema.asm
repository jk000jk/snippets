;  Tema AN II 
;  Chelaru Marius 201
;----------------------------------------------------------------------------------------------
.model small
.stack 100h
.data
    sir_nr db  ('abcde')           ; initializare sir ?

    imp1 dw 5
    n1 dw 0
    n2 dw 0
    n3 dw 0

    i1 db 7 ; 'M' = 77 -> i1 = 7
    i2 db 5 ; 'A' = 65 -> i2 = 5
    i3 db 2 ; 'R' = 82 -> i3 = 2

    C1 db 'C'
    cc1 db 'H'
    nc1 db 'E'

.code

.startup 

    ; ----------------- caracter 1
    
    mov dx, 0  ; setam cu 0 pt a evita erori 
    mov ax, 0  ; setam cu 0 pt a evita erori 
    mov al, i1 
    
    div imp1    ; divide, catul impartirii este in ax, iar restul in dx.
    mov al, dl ; lucram cu acumulatorul
    cmp al, 0  ; seteaza bytes de flag pt a compara cu 0, catul va fi egal cu 0 cand vor fi determinate toate cifrele numarului
    jne rest_1 ; jump not equal to rest_1, daca equal pune 6 in registrul dx 
    mov dx, 6
rest_1:
    mov n1, dx
    mov si, n1
    mov sir_nr[si], '$'  ; terminatorul de sir
afisare_nr_1:
    dec si    ; decrementare
    mov al, C1
    mov sir_nr[si], al   ; sir_nr[source index] = acumulator
    cmp si, 0            ; pregateste compararea
    jne afisare_nr_1     ; daca nu equal cu 0 jump la afisare_nr_1;

    ; afisare
    mov ah, 09h
    mov dx, offset sir_nr  ; offset-ul adresa memorie
    int 21h                ; new line 

    ; ----------------- caracter 2
    
    mov dx, 0  ; setam cu 0 pt a evita erori 
    mov ax, 0  ; setam cu 0 pt a evita erori 
    mov al, i2 
    
    div imp1    ; divide, catul impartirii este in ax, iar restul in dx.
    mov al, dl  ; lucram cu acumulatorul
    cmp al, 0   ; seteaza bytes de flag pt a compara cu 0, catul va fi egal cu 0 cand vor fi determinate toate cifrele numarului
    jne rest_2  ; jump not equal to rest_2, daca equal pune 6 in registrul dx
    mov dx, 6
rest_2:
    mov n2, dx
    mov si, n2
    mov sir_nr[si], '$' ; terminatorul de sir
afisare_nr_2:
    dec si    ; decrementare
    mov al, cc1
    mov sir_nr[si], al   ; sir_nr[source index] = acumulator
    cmp si, 0            ; pregateste compararea
    jne afisare_nr_2     ; daca nu equal cu 0 jump la afisare_nr_2;

    ; afisare
    mov ah, 09h
    mov dx, offset sir_nr  ; offset-ul adresa memorie
    int 21h                ; new line 

    ; ----------------- caracter 3
    
    mov dx, 0  ; setam cu 0 pt a evita erori 
    mov ax, 0  ; setam cu 0 pt a evita erori 
    mov al, i3

    div imp1    ; divide, catul impartirii este in ax, iar restul in dx.
    mov al, dl  ; lucram cu acumulatorul
    cmp al, 0   ; seteaza bytes de flag pt a compara cu 0, catul va fi egal cu 0 cand vor fi determinate toate cifrele numarului
    jne rest_3  ; jump not equal to rest_2, daca equal pune 6 in registrul dx
    mov dx, 6
rest_3:
    mov n3, dx
    mov si, n3
    mov sir_nr[si], '$' ; terminatorul de sir
afisare_nr_3:
    dec si    ; decrementare
    mov al, nc1
    mov sir_nr[si], al   ; sir_nr[source index] = acumulator
    cmp si, 0            ; pregateste compararea
    jne afisare_nr_3     ; daca nu equal cu 0 jump la afisare_nr_3;

    ; afisare
    mov ah, 09h
    mov dx, offset sir_nr  ; offset-ul adresa memorie
    int 21h                ; new line 

    ; terminare program
    mov ah,4ch
    int 21h
end