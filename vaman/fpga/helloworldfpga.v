module helloworldfpga(

    input  wire A,
    input  wire B,
    
    output wire X,
    output wire Y,

    );
   
    
    always @(*)
    begin
    X=(!(!A&(A|B)))|(B);
    Y=(!B)|(!A&(A|B));
    end
    endmodule

