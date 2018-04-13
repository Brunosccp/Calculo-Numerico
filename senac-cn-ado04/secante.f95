

!https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#
!gfortran secante.f95 -o secante
!gfortran bissec.f95 -o secante
!gfortran newton.f95 -o secante

PROGRAM secante
    IMPLICIT NONE
    
    REAL :: x
    !READ *, x
    integer :: y
    y = getInterval(10)
    z = getMid(y, y-1)



    print *, "valor: ", getMid(y, y-1)
    

    contains
    integer function getInterval(x) result(i)
        integer, intent(in) :: x

        do while(i ** 2  < x)
            i = i + 1
        enddo
    end function
    real function getMid(x, y) result(i)
        integer, intent(in) :: x
        integer, intent(in) :: y
        
        i = (x + y) / 2.0

    end function


    function calcSecante(i) result(j)
        integer, intent(in) :: i !input
        integer :: j !output

        !print *, 'entrou na function:',i
        j = i + 3
    END function
    real function calcBisseccao(x) result(j)
    integer, intent(in) :: x


    end function

END PROGRAM secante