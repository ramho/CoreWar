.name "Kaguya"
.comment "A Celestial Being"

loop:     sti r1, %:live, %1
and %3, %7, r1
live:
        live %0
        ld %0, r2
        zjmp %:loop
