!https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#
!gfortran secante.f95 -o secante
!gfortran bissec.f95 -o bissec
!gfortran newton.f95 -o newton

PROGRAM secante
    IMPLICIT NONE

    character(len = 32) :: arg
    double precision :: input

    call get_command_argument(1, arg)

    read(arg, *) input

    print *, calcSecant(input)

    contains
    double precision function calcSecant(x) result(x2)
        double precision, intent(in) :: x
        integer :: i
        double precision :: x0, x1, precision


        x0 = x
        x1 = x - 1
        precision = 0.000000001
        do i = 1, 100000
            x2 = (x0 * x1 + x) / (x0 + x1)
            
            if (abs(x2 - x1) < precision) then
                return
            end if

            x0 = x1
            x1 = x2
        enddo

    end function
        
    


END PROGRAM secante