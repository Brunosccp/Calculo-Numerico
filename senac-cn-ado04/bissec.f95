!https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#
!gfortran secante.f95 -o secante
!gfortran bissec.f95 -o bissec
!gfortran newton.f95 -o secante

PROGRAM bissec
    IMPLICIT NONE
    character(len = 32) :: argv
    integer :: x, y
    
    call get_command_argument(1, argv)
    read(argv, *) x


    print *, calcBisseccao(x, getInterval(x))
    

    contains
    integer function getInterval(x) result(i)
        integer, intent(in) :: x

        do while(i ** 2  < x)
            i = i + 1
        enddo
    end function
    real function getMid(x, y) result(i)
        double PRECISION, intent(in) :: x, y
        
        i = (x + y) / 2.0

    end function
    real function calcBisseccao(x, interval) result(mid)
    integer, intent(in) :: x, interval
    double precision :: min, max, precision
    max = interval
    min = interval-1.0
    mid = getMid(max,min)
    precision = 0.0000001

    do while((max - min) / 2.0 >= precision)
        if (mid ** 2.0 > x) then
            max = mid
        elseif (mid ** 2.0 < x) then
            min = mid
        else
            return
        end if
        mid = getMid(max, min)
        print *, "max - min: ", (max-min)
        
    enddo
    

    end function

END PROGRAM bissec