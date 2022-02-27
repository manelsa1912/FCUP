       .data
_str:  .asciiz  "abracadabra"
_msg:  .asciiz  "The result is "

       .text
_main:
       la      $a0, _str	
       jal     _proc		
       move    $s0, $v0
       la      $a0, _msg
       li      $v0, 4
       syscall
       move    $a0, $s0
       li      $v0, 1
       syscall
       li      $v0, 10
       syscall
_proc:
       li      $v0, 0
_loop:
       lb      $t0, 0($a0)
       beqz    $t0, _exit
       addiu   $v0, $v0, 1
       addiu   $a0, $a0, 1
       j       _loop
_exit:
       jr      $ra
