!https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#
!gfortran secante.f95 -o secante
!gfortran bissec.f95 -o bissec
!gfortran newton.f95 -o newton

PROGRAM newton
    IMPLICIT NONE

    character(len = 32) :: arg
    double precision :: input

    call get_command_argument(1, arg)

    read(arg, *) input

    print *, calcNewton(input)

    contains
    double precision function calcNewton(x) result(x2)
        double precision, intent(in) :: x
        double precision :: x1, precision
        integer :: i

        x1 = x
        precision = 0.000000001
        do i = 1, 100000
            x2 = (x1 + input/x1) / 2
                
            if(abs(x2 - x1) < precision) then
                return
            end if

            x1 = x2
        enddo
    end function
        
    


END PROGRAM newton