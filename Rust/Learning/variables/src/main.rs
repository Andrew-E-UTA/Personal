fn main() 
{
    let var = 4;        // implicitly immutable and assigned as int
    //(i.e. unless 'mut' is explicitly added, var can't change)
    println!("Example printing variable: {}", var);
    println!("Another Example: {var}");

    let name : &str = "Mr. Robot";
    println!("My name is {name}");

    //SHADOWING
    let weight = 10;
    println!("Scale reads: {weight}");
    let weight = 50;    // basically 'Redeclares' weight variable
    println!("Scale reads: {weight}");

    {                   // within sub-scope, u can shadow weight
                        //but once we leave this scope, weight will
                        //go back to its previous.
        let weight = "Fat";
        println!("Scale reads: {weight}");
    }
    println!("Scale reads: {weight}");

    //VARIABLES
        //Scalar
            // integers:
                // 8 -> 128 bit
                // signed (i)
                // unsigned (u)
                // 'size' the size of your cpu
            // floats:
                // f32 f64
            // boolean
                // bool
            // character
                // char  ''
        //Compound
            // tuple
                // its type is the types of its contents 
                // Access by: <name>.<index>
            // array
                // let <name> = [elements];
                //let <name>: [<type>;<size>] = [elements];
                // dne empty arrays 
            // strings
            //

    let x: u8 = 128;
    let y: u32 = x as u32;
    println!("{y}");
    
    //need _f<size> to do floats
    let mut f = 135.135325_f32;
    f += 100.0;
    println!("{f}");
    
}
