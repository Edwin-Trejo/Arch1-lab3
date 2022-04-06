#I received help from Christian Gomez while working on tracer.

.global tracer  

tracer:         
        mv a0,sp        #copies the value from register a0, to register sp which is the stack pointer.
        jalr x0,0(x1)   #jump and link register
