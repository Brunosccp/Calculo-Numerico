!https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#
!gfortran bhaskara.f08 -o bhaskara

PROGRAM bhaskara
    IMPLICIT NONE
    character(len=32) :: argv
    integer :: a,b,c
    integer :: r, i, n

    call get_command_argument(1, argv)
    read(argv, *) a

    call get_command_argument(2, argv)
    read(argv, *) b

    call get_command_argument(3, argv)
    read(argv, *) c

    !print *, a,b,c

    n = bhaskaraCalc(a,b,c)

    contains
    real function delta(a, b, c) result (r)
        integer, intent(in) :: a, b, c

        r = b**2 - 4 * a * c
    end function delta

    integer function bhaskaraCalc(a, b, c)
        integer, intent(in) :: a,b,c
        real :: d
        real :: r1, r2, i1, i2

        d = delta(a,b,c)

        if(d >= 0) then

            r1 = (-b + sqrt(d)) / 2*a
            r2 = (-b - sqrt(d)) / 2*a

            write(*, '(A, f0.1)') 'r1 = ', r1
            write(*, '(A, f0.1)') 'r2 = ', r2

        else
            d = d * (-1)
            

            r1 = (-b) / (2.0*a)
            i1 = sqrt(d) / (2.0*a)

            write(*, '(A,f0.1, A, f0.1, A)') 'r1 = ', r1, ' + ', i1, 'i'
            write(*, '(A,f0.1, A, f0.1, A)') 'r2 = ', r1, ' - ', i1, 'i'

        end if

        return
    end function bhaskaraCalc
END PROGRAM bhaskara