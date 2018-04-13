

!https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#
!gfortran secante.f95 -o secante
!gfortran bissec.f95 -o secante
!gfortran newton.f95 -o secante

PROGRAM bissec
    IMPLICIT NONE
    
    integer :: x, y
    y = getInterval(9)
    


    print *, "valor: ", calcBisseccao(x, y)
    

    contains
    integer function getInterval(x) result(i)
        integer, intent(in) :: x

        do while(i ** 2  < x)
            i = i + 1
        enddo
    end function
    real function getMid(x, y) result(i)
        real, intent(in) :: x, y
        
        i = (x + y) / 2.0

    end function

    real function calcBisseccao(x, interval) result(mid)
    integer, intent(in) :: x, interval
    real :: min, max, precision
    max = interval
    min = interval-1.0
    mid = getMid(max,min)
    precision = 0.01

    do while((max - min) / 2.0 >= precision)
        if (mid ** 2.0 > x) then
            max = mid
        elseif (mid ** 2.0 < x) then
            min = mid
        else
            return
        end if
        mid = getMid(max, min)
    enddo
    

    end function

END PROGRAM bissec