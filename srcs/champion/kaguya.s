.name "Kaguya"
.comment "A Celestial Being"

loop:     sti r1, %:li, %1
and %3, %7, r1
ld :loop,r1
li:
        live %0
        ld %0, r2
        zjmp %:loop
