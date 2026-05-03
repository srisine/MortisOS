; ISR stubs for x86_64
; Works with isr.c handlers

BITS 64

global isr_common
extern isr_handler

; --------------------------------------------------
; Common ISR stub (called by individual ISRs)
; --------------------------------------------------
isr_common:
    ; --- Save general purpose registers ---
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    ; --- Save error code / interrupt number is already pushed by stub ---
    mov rdi, rsp    ; pointer to registers_t
    call isr_handler

    ; --- Restore registers ---
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax

    add rsp, 16      ; remove pushed error code & interrupt number
    iretq             ; return from interrupt

; --------------------------------------------------
; Macros to generate ISR stubs
; --------------------------------------------------
%macro ISR_NO_ERROR_CODE 1
global isr%1
isr%1:
    push 0           ; dummy error code
    push %1          ; interrupt number
    jmp isr_common
%endmacro

%macro ISR_ERROR_CODE 1
global isr%1
isr%1:
    push %1          ; interrupt number
    jmp isr_common
%endmacro

; --------------------------------------------------
; CPU exceptions 0-31
; Error codes for exceptions with one
ISR_NO_ERROR_CODE 0
ISR_NO_ERROR_CODE 1
ISR_NO_ERROR_CODE 2
ISR_NO_ERROR_CODE 3
ISR_NO_ERROR_CODE 4
ISR_NO_ERROR_CODE 5
ISR_NO_ERROR_CODE 6
ISR_NO_ERROR_CODE 7
ISR_ERROR_CODE    8   ; Double fault
ISR_NO_ERROR_CODE 9
ISR_ERROR_CODE   10   ; Invalid TSS
ISR_ERROR_CODE   11   ; Segment not present
ISR_ERROR_CODE   12   ; Stack fault
ISR_ERROR_CODE   13   ; General protection fault
ISR_ERROR_CODE   14   ; Page fault
ISR_NO_ERROR_CODE 15
ISR_NO_ERROR_CODE 16
ISR_NO_ERROR_CODE 17
ISR_NO_ERROR_CODE 18
ISR_NO_ERROR_CODE 19
ISR_NO_ERROR_CODE 20
ISR_NO_ERROR_CODE 21
ISR_NO_ERROR_CODE 22
ISR_NO_ERROR_CODE 23
ISR_NO_ERROR_CODE 24
ISR_NO_ERROR_CODE 25
ISR_NO_ERROR_CODE 26
ISR_NO_ERROR_CODE 27
ISR_NO_ERROR_CODE 28
ISR_NO_ERROR_CODE 29
ISR_NO_ERROR_CODE 30
ISR_NO_ERROR_CODE 31

; --------------------------------------------------
; IRQs 32-47 (dummy error code)
ISR_NO_ERROR_CODE 32
ISR_NO_ERROR_CODE 33
ISR_NO_ERROR_CODE 34
ISR_NO_ERROR_CODE 35
ISR_NO_ERROR_CODE 36
ISR_NO_ERROR_CODE 37
ISR_NO_ERROR_CODE 38
ISR_NO_ERROR_CODE 39
ISR_NO_ERROR_CODE 40
ISR_NO_ERROR_CODE 41
ISR_NO_ERROR_CODE 42
ISR_NO_ERROR_CODE 43
ISR_NO_ERROR_CODE 44
ISR_NO_ERROR_CODE 45
ISR_NO_ERROR_CODE 46
ISR_NO_ERROR_CODE 47

; --------------------------------------------------
; Syscall stub (e.g., 128)
ISR_NO_ERROR_CODE 128



